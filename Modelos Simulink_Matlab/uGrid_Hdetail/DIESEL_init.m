function [ output_args ] = DIESEL_init( input_args )
ttInitKernel('prioFP') 
data.exectime = 1e-6; % se inicializa porque true time lo requiere pero no se usa 
starttime = 4; % tiempo de arranque del controlador 
period = 0.0001; % periodo de muestreo 
ttCreatePeriodicTask('ctrl_task', starttime, period, 'DIESEL_c', data)
end