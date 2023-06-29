% Author : Miroslav Marinkovic
% E-mail : mmarinkovic78d@gmail.com
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function s = bch_code_struct(n_max, k_max, n, prim_poly)
% n_max : maximum number of bits per BCH codeword. It must be of form 2^m-1
% k_max : maximum number of data bits per BCH codeword
% Values n_max and k_max must produce a valid narrow-sense BCH code
% n : actual code length in bits
% prim_poly : primitive polynomial for GF(2^m) = primpoly(m)
s = [];
m = log2(n_max + 1); % integer between 3 and 16 to define GF(2^m)
n_max = 2^m - 1; % maximum number of bits per BCH codeword
k = n - (n_max - k_max); % actual number of data bits per BCH codeword
% Generator polynomial 
[gen_poly, t] = bchgenpoly(n_max, k_max, prim_poly);
% save parameters in the structure
s.m = m;
s.n = n;
s.k = k;
s.t = t;
s.n_max = n_max;
s.k_max = k_max;
s.prim_poly = prim_poly;
gp = uint32(gen_poly.x);
gp = fliplr(gp);
s.gp = gp;
% calculate alpha power
alpha = gf(2, m, prim_poly); % primitive element 'alpha' of GF(2^m)
ap = alpha.^(0:n_max);
alpha_power = uint32(ap.x);
s.alpha_power = alpha_power;
index_gf_element = zeros(1, n_max+1);
% find GF element in alpha_power array 
for nn = 2:n_max + 1
  index_gf_element(nn) = find(nn-1 == alpha_power(1:n_max));
end
 
s.index_gf_element = index_gf_element;
 
% create alpha array
nn = 1:2*t;
alpha_synd = alpha.^nn;
alpha_synd_num = uint32(alpha_synd.x);
s.alpha_synd = alpha_synd_num;