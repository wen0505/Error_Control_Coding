% BCH code
% The degree 3 polynomial P(x) = x3+x+1 = (1011) = 11
a = gf(2,3,11);     % Let a=2 in this GF(2^3)
M = minpol(a^3);   % M = minimal polynomial for a^3 
disp(M.x);          % Show M in binary form           

x = a^3;           % Let x=a^3 in this GF(8)

x^3 + x^2 + 1       % Show that a^3 is a root of M

% Let G(x) be an (7,4) BCH Generator Polynomial based on P(x) = D^3+D+1 (1011 binary = 11 decimal)
[G,t] = bchgenpoly(7,4,11); % return generator polynomial for BCH (7,4) code

disp(t)   % show t = number of correctable bits
disp(G.x) % show the generator polynomial