function HeatProp
% Parametri fisici
eta = 0.45; L = 0.5; kappa = 10;
% Delta x, Delta t
N = 101; x = linspace(0.0,L,N);
dx = x(2)-x(1); dt = (eta*dx^2)/kappa; % eta = kappa*dt/dx^2
% Impulso di calore iniziale e condizioni al contorno
T0 = 20; DeltaT = 80;
T = ones(N,1)*T0;
T((N+1)/2) = T0+DeltaT;
plot(x,T,'*b');
% ....
% Evoluzione
t = 0; tend = 1e-4;
while t<tend
    T(2:end-1)=T(2:end-1)+eta*(T(3:end)-2*T(2:end-1)+T(1:end-2));
    % Assegno componente per componente, sposto tutto a dx/sx di 1
    plot(x,T);


    % iterazione
    % ....
    drawnow limitrate nocallbacks
    t = t+dt; 
    end
    sigma=sqrt(2*kappa*t);
    fgaus=@(x)[T0+DeltaT*dx*normpdf(x,L/2,sigma)];
    hold on;
    fplot (fgaus,[0 L]);
    hold off;
