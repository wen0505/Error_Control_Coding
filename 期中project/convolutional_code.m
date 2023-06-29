g=[1 1 1;1 0 1]; %generator polynomials
[n,K] = size(g);
m = K-1; %number of registers
state = zeros(1,m);%set registers to zero
inputx=[0 1 0 1 1 1 0 0 1 0 1 0 0 0 1]; %encoder input source code
[trash,h]=size(inputx);
outputy=[];
for x=1:h %h=number of input bits
    input=inputx(1,x);
for i=1:n
   output(i) = g(i,1)*input;
   for j = 2:K
       z=g(i,j)*state(j-1);
      output(i) = xor(output(i),z);
   end;
end
state = [input, state(1:m-1)];
outputy=[outputy,output]; %new element added to sequence
end
outputy %final encoder output in command window
