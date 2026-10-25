function [med,dstd] = MedDevSta(x)
N=numel(x);
med=sum(x)/N;
med2=sum(x.*x)/N;
var=med2-med*med;
dstd=sqrt(var);
end
