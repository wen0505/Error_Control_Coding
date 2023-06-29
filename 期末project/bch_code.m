% MATLAB simulation of BCH code and decode m file
% BCH Encoder
clear all;
clc;
m = 4;
n = 2^m-1;  % Codeword length
k = 5;  % Message length
m=[1 1 1 0 1];  % input('Enter message of length 5 :');
msg = gf(m);
disp('Message:');
disp(msg);

% Find t, the error-correction capability.
[ggenpoly,t] = bchgenpoly(n,k);
disp('Error correcy capability:');
disp(t);

% Encode the message.
code = bchenc(msg,n,k);
disp('Encoded Message:');
c = gf(code);
disp(c);
noisycode = code + randerr(1,n,1:t);
disp('Received Codeword:');
disp(noisycode);

% Decode the noisy code.
[newmsg,err,ccode] = bchdec(noisycode,n,k);
disp('Decoded Codeword:');
disp(newmsg);
if msg==newmsg
    disp('The message was recovered perfectly.');
else
    disp('Error in recovery of message.');
end
