x=[1 2 3 4];
N=4;
med=sum(x)/N;
med2=sum(x.*x)/N;
var=med2-med*med;
dstd=sqrt(var);
disp(med);
disp(dtsd);