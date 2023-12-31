% Author : Miroslav Marinkovic
% E-mail : mmarinkovic78d@gmail.com
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [y] = gf_mul(x1, x2, s)
% GF multiplier
% x1: row integer vector 
% x2: row integer vector 
% y: product vector 
% it uses structure generated by RS or BCH code structure
alpha_power = s.alpha_power;
index = s.index_gf_element;
n_max = s.n_max;
alpha_index = mod((index(x1+1)+index(x2+1)-2), n_max);
% calculate product vector
y = uint32(logical(x1)).*uint32(logical(x2)).*uint32(alpha_power(alpha_index+1));
    
end