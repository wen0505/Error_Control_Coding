x1=[1];
x2=[1];
x3=[0];
x4=[1];

r11=[0];
r12=[0];
r13=[0];
m=[x1 x2 x3 x4];

r21=rem(r13+x1,2);
r22=rem(x1+r11+r13,2);
r23=r12;
c1=x1;
r1=[r21 r22 r23]

r31=rem(r23+x2,2);
r32=rem(x2+r21+r23,2);
r33=r22;
c2=x2;
r2=[r31 r32 r33]

r41=rem(r33+x3,2);
r42=rem(x3+r31+r33,2);
r43=r32;
c3=x3;
r3=[r41 r42 r43]

r51=rem(r43+x4,2);
r52=rem(x4+r41+r43,2);
r53=r42;
c4=x4;
r4=[r51 r52 r53]

c5=r53;
c6=r52;
c7=r51;
c=[c7 c6 c5 c4 c3 c2 c1]