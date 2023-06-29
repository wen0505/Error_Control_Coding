function y=index(x)
n=63;m=6;
alpha=zeros(n+1,m);
alpha(2:m+1,:)=eye(m);
for i=m+2:n+1
 alpha(i,:)=mod(alpha(i-m,:)+alpha(i-m+1,:),2);
end
for i=1:n+1
 if x==alpha(i,:)
 y=i-1;
 end
end 