%% bch params
M = 7;
n = 2^M-1;   % Codeword length
k = 15;       % Message length
nwords = 2; % Number of words to encode
% create a msg
msgTx = gf(randi([0 1],nwords,k));
%disp(msgTx)
%Find the error-correction capability.
t = bchnumerr(n,k)
% Encode the message.
enc = bchenc(msgTx,n,k);
%Corrupt up to t bits in each codeword.
noisycode = enc + randerr(nwords,n,1:t);
%Decode the noisy code.
msgRx = bchdec(noisycode,n,k);
% Validate that the message was properly decoded.
isequal(msgTx,msgRx)