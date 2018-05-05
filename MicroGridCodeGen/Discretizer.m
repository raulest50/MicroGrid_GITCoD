% OVERVIEW:
% este script lo que hace es hacer la discretizacion de los
% bloques continuos del modelo de simulink SFlowModel.
% la idea es que el proceso de discretizacion quede automatizado
% en este script de forma tal que si se debe hacer un cambio en
% en los modelos continuos se pueda recalcular de forma facil,
% rapida y confiable los equivalentes discretos las veces que 
% sea necesario.
%
% para que este script pueda funcionar deben tenerse abiertos los
% modelos de simulink SFlowModel.slx y SFlowDiscrete.slx .

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
% CONVENCION PARA LOS NOMBRES DE LAS VARIABLES.

% sm_ indica que es un nombre de un bloque de simulink.
% smp_ indica que es el nombre de un parametro de un simulink block.
% tfZ_ indica que es una funcion de transferencia en Z.

% sm2_   indica un bloque de simulink del modelo discreto (archivo destino)
% smp2_  indica que es un nombre de parametro de bloque en el modelo
%        discreto
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  CALCULOS DE CONTINUO A DISCRETO.
%%%%%%%%%%%

% El usuario de este script debe definir los tiempos de muestreo 
% y los pasos de tiempo deseados en segundos.

Ts_sim = 1e-7; % paso de simulacion de la microred.
Ts_mpc = .03; % periodo de muestreo de la etapa de control.


% la informacion del modelo de simulink se accede mediante la funcion
% get_param, el cual necesita el nombre del archivo de simulink
% y el nombre de los bloques. a continuacion se definen estos
% nombres en variables para mayor claridad del algoritmo
slx = 'SFlowModel';
sm_bio = [ slx '/H1-G1' ];
sm_diesel = [ slx '/H2-G2' ];
sm_load = [ slx '/Z_load' ];
sm_ph_shift = [ slx '/PhaseShift' ];

smp_N = 'N'; % numerador de un Fcn block
smp_D = 'D'; % denominador de un Fcn block

% la conductancia de linea se implemento usando una matlab
% function y un integrador. por tanto no se discretiza a z.

Num_bio = str2num(get_param(sm_bio, smp_N));
Den_bio = str2num(get_param(sm_bio, smp_D));
tfZ_bio = c2d(tf(Num_bio, Den_bio), Ts_sim, 'foh');

Num_diesel = str2num(get_param(sm_diesel, smp_N));
Den_diesel = str2num(get_param(sm_diesel, smp_D));
tfZ_diesel = c2d(tf(Num_diesel, Den_diesel), Ts_sim, 'foh');

% se discretiza el desfase de 90 grados que se usa para obtener
% un equivalente en beta para cada ac waveform que fuere necesaria.
Num_ph_shift = str2num(get_param(sm_ph_shift, smp_N));
Den_ph_shift = str2num(get_param(sm_ph_shift, smp_D));
tfZ_fShift = c2d(tf(Num_ph_shift, Den_ph_shift), Ts_sim);


Num_load = str2num(get_param(sm_load, smp_N));
Den_load = str2num(get_param(sm_load, smp_D));
tfZ_load = c2d(tf(Num_load, Den_load), Ts_sim);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% A este punto ya se tienen todos los datos necesarios para
% implementar el equivalente discreto. En lo que sigue del
% script se escriben los datos correspondientes en el 
% modelo SFlowDiscrete

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ESCRITURA DE LOS MODELOS AL SLX SFlowDiscrete.
%%%%%%%%%%%%%%

% declaracion de nombres.

smp2_TsMfc = 'SystemSampleTime'; % parametro Ts matlabFunctions
smp2_Tsint = 'SampleTime';

slx2 = 'SFlowDiscrete'; % modelo discreto signal flow
sm2_bio = [slx2 '/BIO']; % convertidor biomasa discreto
sm2_diesel = [slx2 '/DIESEL']; % convertidor diesel discreto
sm2_load = [ slx2 '/ZL']; % impedancia de la carga

% bloques de desfase de 90 para las corrientes de los convertidores y la
% tension en la carga.
sm2_shift = [slx2 '/Z90Shift'];
sm2_shift1 = [slx2 '/Z90Shift1'];
sm2_shift2 = [slx2 '/Z90Shift2'];

sm2_vs = [slx2 '/Vs'];% se�al seno de fuente AC ideal


% bloques tipo matlabfunction.
sm2_pq_diesel = [ slx2 '/pq_diesel' ]; % pq iref diesel
sm2_pq_bio = [ slx2 '/pq_bio' ]; % pq iref bio
sm2_p2r = [ slx2 '/P2r' ]; % relacion potencia fuente alternativa impedancia de linea.
sm2_pq_meas_bio = [slx2 '/pq_meas_bio']; % blk medicion pq bio
sm2_pq_meas_diesel = [slx2 '/pq_meas_diesel']; % blk medicion pq diesel
sm2_linprog = [slx2 '/LinearProg']; % bloque de programacion lineal
sm2_ren_maxP = [slx2 '/RenewableMaxPower']; % calcula la potencia maxima
sm2_ys = [slx2 '/Ys'];
% que puede entregar las renovables.

sm2_vsiint = [ slx2 '/VSI_int' ]; % integrador modelo conductancia de linea VSI


% se configuran las tf z de los convertidores diesel bio y la carga.
set_param(sm2_bio, 'Denominator', '[]');
set_param(sm2_bio, 'Numerator', '[]');
set_param(sm2_bio, 'Denominator', [ '[' num2str(tfZ_bio.Denominator{1}) ']' ]);
set_param(sm2_bio, 'Numerator', [ '[' num2str(tfZ_bio.Numerator{1}) ']' ]);

set_param(sm2_diesel, 'Denominator', '[]');
set_param(sm2_diesel, 'Numerator', '[]');
set_param(sm2_diesel, 'Denominator', [ '[' num2str(tfZ_diesel.Denominator{1}) ']' ]);
set_param(sm2_diesel, 'Numerator', [ '[' num2str(tfZ_diesel.Numerator{1}) ']' ]);

set_param(sm2_load, 'Denominator', '[]');
set_param(sm2_load, 'Numerator', '[]');
set_param(sm2_load, 'Denominator', [ '[' num2str(tfZ_bio.Denominator{1}) ']' ]);
set_param(sm2_load, 'Numerator', [ '[' num2str(tfZ_bio.Numerator{1}) ']' ]);

% se configuran los 3 bloques de desfase.
set_param(sm2_shift, 'Denominator', '[]');
set_param(sm2_shift, 'Numerator', '[]');
set_param(sm2_shift, 'Denominator', [ '[' num2str(tfZ_fShift.Denominator{1}) ']' ]);
set_param(sm2_shift, 'Numerator', [ '[' num2str(tfZ_fShift.Numerator{1}) ']' ]);

set_param(sm2_shift1, 'Denominator', '[]');
set_param(sm2_shift1, 'Numerator', '[]');
set_param(sm2_shift1, 'Denominator', [ '[' num2str(tfZ_fShift.Denominator{1}) ']' ]);
set_param(sm2_shift1, 'Numerator', [ '[' num2str(tfZ_fShift.Numerator{1}) ']' ]);

set_param(sm2_shift2, 'Denominator', '[]');
set_param(sm2_shift2, 'Numerator', '[]');
set_param(sm2_shift2, 'Denominator', [ '[' num2str(tfZ_load.Denominator{1}) ']' ]);
set_param(sm2_shift2, 'Numerator', [ '[' num2str(tfZ_load.Numerator{1}) ']' ]);


% se establecen los tiempos de muestreo de las m functions relacionadas con
% el control de potencia.
set_param(sm2_pq_diesel, smp2_TsMfc, num2str(Ts_mpc));
set_param(sm2_pq_bio, smp2_TsMfc, num2str(Ts_mpc));
set_param(sm2_pq_meas_bio, smp2_TsMfc, num2str(Ts_mpc));
set_param(sm2_pq_meas_diesel, smp2_TsMfc, num2str(Ts_mpc));
set_param(sm2_linprog, smp2_TsMfc, num2str(Ts_mpc));
set_param(sm2_ren_maxP, smp2_TsMfc, num2str(Ts_mpc));

% se establecen los Ts de los bloques relacionados con el paso de
% simulacion.
set_param(sm2_p2r, smp2_TsMfc, num2str(Ts_sim));
set_param(sm2_ys, smp2_TsMfc, num2str(Ts_sim));

% se configura tiempo de muestreo del integrador
set_param(sm2_vsiint, smp2_Tsint, num2str(Ts_sim));

% se configura tiempo de muestreo de la se�al AC Vs fuente ideal
set_param(sm2_vs, smp2_Tsint, num2str(Ts_sim));

% se configura el fixed step size del modelo
set_param(slx2, 'FixedStep', num2str(Ts_sim));


clearvars -except Ts_mpc Ts_sim;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% COSTRUCCION DEL OBJ MPC PARA EL TIEMPO DE MUESTREO DEFINIDO.
%%%%%%%%%%%%%% (copy paste del codigo de Mario Paredes)


pruebaft2ss;
% calculo del controlador MPC

%se carga el state space model desde linear analysis simulink
%load('statespaceModel_2Inverters_prver.mat');

A = sis.A; %linsys1.A;
B = sis.B; %linsys1.B;
C = sis.C; %linsys1.C;
D = sis.D; %linsys1.D;

CSTR = ss(A,B,C,D);
CSTR.InputName = {'Pr1','Qr1','Pr2','Qr2'};
CSTR.OutputName = {'P1','Q1','P2','Q2'};
CSTR.StateName = {'X1', 'X2', 'X3', 'X4'};


% Create the controller object with sampling period, prediction and control horizons:
plant=CSTR;
Ts = Ts_mpc;
p = 10;
m = 8;
mpcobj = mpc(plant, Ts, p, m);


% Specify actuator saturation limits as MV constraints.
mpcobj.MV = struct('Min',{0;0;0;0},'Max',{700;5000;700;5000},'RateMin',{ones(4, 1)*-2000}, 'RateMax',{ones(4, 1)*2000});
% Simulate Using Simulink�


% en caso de que hayan estdos no observables este comando
% transforma el modelo para evitar este problema
mpcobj.Model.Plant = minreal(mpcobj.Model.Plant);


% se limpian las variables, ya no son necesarias ya que todos los datos ya
% se escribieron al modelo de simulink SFlowDiscrete.
clearvars -except mpcobj;