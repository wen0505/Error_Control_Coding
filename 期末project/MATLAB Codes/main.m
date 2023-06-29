clear all,clc,format long
n=63;m=6;k=36;t=5;
%G: Generator matrix in symmetric form
%alpha: m-tuples representation of the field elements
%mes: Message data stream
%c: Code word corresponding to mes
%cpbsk: Baseband BPSK version of c
%SNR: Signal-to-noise ratio for the uncoded system
%uvar: Gaussian noise variance for the uncoded system
%cvar: Gaussian noise variance for the coded system
%cn: Noisy version of cpbsk
%r: Transmitted code word
%e: Error code vector
%d: Demodulated received code word
%dmes: Demodulated message data
%Generator matrix
G=zeros(k,n);
for i=1:k
 G(i,i:n-k+i)=bchpoly(n,k);
end
B=G(:,n-k+1:n);
G=mod(mod(inv(B),2)*G,2);
%Alpha-Index look-up tables
alpha=zeros(n+1,m);
alpha(2:m+1,:)=eye(m);
for i=m+2:n+1
 alpha(i,:)=mod(alpha(i-m,:)+alpha(i-m+1,:),2);
end
%Data encoding,decoding and Pe calculations
ind=1;L=3e4;
for SNR=0:8
 Pe(ind)=0;
 for l=1:L
 r=zeros(1,n);d=zeros(1,n);cbpsk=zeros(1,n);e=zeros(1,n);
 mes=round(rand(1,k));
 c=mod(mes*G,2);
 for j=1:n
 if c(j)==0
 cbpsk(j)=-1;
 else
 cbpsk(j)=1;
 end
 end
 uvar=10^(-SNR/10)/2;
 cvar=uvar*n/k;
 Gn=sqrt(cvar)*randn(1,n);
 cn=cbpsk+Gn;
 for j=1:n
 if cn(j)<0
 r(j)=0;
  else
 r(j)=1;
 end
 end
 %Syndromes calculation
 S=zeros(2*t,m);s=zeros(1,2*t);
 for i=1:2*t
 for j=1:n
 if r(j)==0
 S(i,:)=S(i,:);
 else
 S(i,:)=mod(S(i,:)+alpha(rem(i*j-i,n)+2,:),2);
 end
 end
 s(i)=index(S(i,:))-1;
 end
 %Data decoding using Berlekamp's algorithm
 lmd=zeros(1,t);T=zeros(1,t);
 lmd(1)=s(1);
 if s(1)==-1
 T(1)=-1;T(2)=0;
 else
 T(1)=mod(n-s(1),n);
 end
 for v=1:t-1
 deltar=alpha(rem(s(2*v+1),n)+2,:);
 for j=1:v
 if lmd(j)==-1 | s(2*v+1-j)==-1
 deltar=deltar;
 else
 deltar=mod(deltar+alpha(rem(lmd(j)+s(2*v+1-j),n)+2,:),2);
 end
 end
 delta=index(deltar)-1;
 V=lmd;
 if delta==-1 |T(v)==-1
 lmd(v+1)=-1;
 else
 lmd(v+1)=rem(delta+T(v),n);
 end
 for i=2:v
 if delta==-1 |T(i-1)==-1
 lmdr=alpha(rem(lmd(i),n)+2,:);
 else
 lmdr=mod(alpha(rem(lmd(i),n)+2,:)+alpha(rem(T(i-1)+delta,n)+2,:),2);
 end
 lmd(i)=index(lmdr)-1;
 end
 if delta~=-1
 T(1)=mod(n-delta,n);
 for i=2:v+1
 T(i)=mod(V(i-1)-delta,n);
 end
 else 
      T(v+2)=T(v);
 for j=1:v+1
 T(j)=0;
 end
 end
 end
 %Error locations using Chien's algorithm
 for i=0:n-1
 xx=zeros(1,m);
 for j=1:t
 if lmd(j)==-1
 xx=xx;
 else
 xx=mod(xx+alpha(rem(lmd(j)+j*i,n)+2,:),2);
 end
 end
 if index(xx)==1
 e(mod(n-i,n)+1)=1;
 end
 end
 d=mod(r+e,2);
 dmes=d(:,n-k+1:n);
 for i=1:k
 if dmes(i)~=mes(i)
 Pe(ind)=Pe(ind)+1;
 end
 end
 end
 Pe(ind)=Pe(ind)/(k*L);
 ind=ind+1;
end
SNR=0:8;
semilogy(SNR,0.5*erfc(sqrt(10.^(SNR/10))),'--');
hold
semilogy(SNR,Pe) 