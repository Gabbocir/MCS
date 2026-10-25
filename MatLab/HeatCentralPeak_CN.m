function HeatCentralPeak_CN
% Parametri fisici
eta = 0.30;  L = 0.5; kappa = 10;
% Delta x, Delta t
N   = 101;  
x   = linspace(0.0,L,N); 
dx  = x(2)-x(1);
dt  = (eta*dx^2)/kappa;
% Impulso di calore iniziale
T0           = 20;
DeltaT       = 80;
T            = ones(N,1)*T0;
T((N-1)/2+1) = T0+DeltaT;
% Evoluzione temporale
t    = 0; tend = 1e-3;
while t<tend
    plot(x,T);
    y=MyFunction(eta,T);
    T(1)=20;
    T(2:N-1) = y;
    T(N) = 20;
    drawnow;
    t = t+dt;
end
% Confronto con soluzione analitica
sigma = sqrt(2*kappa*t);
Tteo = T0+DeltaT*dx*normpdf(x,L/2,sigma);
hold on;
plot(x,Tteo);
hold off;
end

function [y] = MyFunction (eta, x)
N=numel(x);

b=zeros(N-2,1);
b(1:N-2)=x(1:N-2)+((2/eta)-2)*x(2:N-1)+x(3:N);
b(1)=b(1)+x(1);
b(N-2)=b(N-2)+x(N);

v=ones(N-3,1);
C=((2/eta)+2)*eye(N-2)-diag(v,-1)-diag(v,+1);

y=C\b;

end

