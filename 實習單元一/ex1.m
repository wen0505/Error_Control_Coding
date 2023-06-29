
x1=1;
x2=1;
x3=0;
x4=1;
x5=0;
x6=1;
x7=0;
x=[x1 x2 x3 x4 x5 x6 x7];

y1=1;
y2=1;
y3=0;
y4=1;
y5=0;
y6=0;
y7=0;
y=[y1 y2 y3 y4 y5 y6 y7];

A=rem(y1+y2+y3+y5,2);
B=rem(y1+y2+y4+y6,2);
C=rem(y1+y3+y4+y7,2);

if A==0&&C==0&&B==1
    y6=rem(y6+1,2);
    y=[y1 y2 y3 y4 y5 y6 y7];
elseif A==0&&B==0&&C==1
    y7=rem(y7+1,2);
    y=[y1 y2 y3 y4 y5 y6 y7];
elseif B==0&&C==0&&A==1
    y5=rem(y5+1,2);
    y=[y1 y2 y3 y4 y5 y6 y7];
end