function HeatLeftPeak_Explicit
% Parametri fisici
eta = 0.45;  L = 0.5; kappa = 10;
% Delta x, Delta t
N   = 101;  
x   = linspace(0.0,L,N); 
dx  = x(2)-x(1);
dt  = (eta*dx^2)/kappa;
% Impulso di calore iniziale
T0           = 20;
DeltaT       = 80;
T            = ones(1,N)*T0;
T(1)         = T0+DeltaT;
% Evoluzione temporale
t    = 0; tend = 1e-3;
% Creazione vettori dinamici per grafico andamento temperatura in un punto
xTerm = 10;
timeHistory = [];
temperatureHistory = [];

while t<tend
    plot(x,T);
    T_0=T(2);
    T(2:end-1)=T(2:end-1)+eta*(T(3:end)-2*T(2:end-1)+T(1:end-2));
    T(1)=T(1)+eta*(T_0+T_0-2*T(1));
 % Avrei problemi nella seconda riga (a prescindere dall'ordine) perché o
 % uso T(2) aggiornato o T(1) aggiornato, per risolvere scelgo questa e al
 % posto di T(2) metto T_0 che è quello non aggiornato

    timeHistory(end+1) = t;
    temperatureHistory(end+1) = T(xTerm);
    % Salvataggio t e T (per un punto x_term della sbarra)

    drawnow limitrate nocallbacks
    t = t+dt;
end
figure(2);
plot(timeHistory,temperatureHistory);
% Grafico T(x_term) vs t
end