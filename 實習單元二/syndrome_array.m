G = [ 1 0 0 1 1 0
      0 1 0 1 0 1
      0 0 1 0 1 1 ];
  
u1=[1 0 0];
u2=[0 1 0];
u3=[0 0 1];
u4=[u1+u2];
u5=[u1+u3];
u6=[u2+u3];
u7=[u1+u2+u3];

c0=[0 0 0 0 0 0];
e1=[0 0 0 0 0 1];
e2=[0 0 0 0 1 0];
e3=[0 0 0 1 0 0];
e4=[0 0 1 0 0 0];
e5=[0 1 0 0 0 0];
e6=[1 0 0 0 0 0];
e7=[1 0 0 0 0 1];
e=[c0;e1;e2;e3;e4;e5;e6;e7]

c0=[0 0 0 0 0 0];
c1=rem([u1*G],2);
c2=rem([u2*G],2);
c3=rem([u3*G],2);
c4=rem([u4*G],2);
c5=rem([u5*G],2);
c6=rem([u6*G],2);
c7=rem([u6*G],2);
c=[c0;c1;c2;c3;c4;c5;c6;c7]

n0=zeros(8,6);
n1=zeros(8,6);
n2=zeros(8,6);
n3=zeros(8,6);
n4=zeros(8,6);
n5=zeros(8,6);
n6=zeros(8,6);
n7=zeros(8,6);
n1(1,:)=c1;
n2(1,:)=c2;
n3(1,:)=c3;
n4(1,:)=c4;
n5(1,:)=c5;
n6(1,:)=c6;
n7(1,:)=c7;
n0=c;

for i=2:1:8
    n1(i,:)=rem([c(2,:)+e(i,:)],2);
    n2(i,:)=rem([c(3,:)+e(i,:)],2);
    n3(i,:)=rem([c(4,:)+e(i,:)],2);
    n4(i,:)=rem([c(5,:)+e(i,:)],2);
    n5(i,:)=rem([c(6,:)+e(i,:)],2);
    n6(i,:)=rem([c(7,:)+e(i,:)],2);
    n7(i,:)=rem([c(8,:)+e(i,:)],2);
end

w=[n0 n1 n2 n3 n4 n5 n6 n7]