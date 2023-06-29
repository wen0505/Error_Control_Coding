a = gf( [1 1 1 0 0 1 0 1], 3, 11 );
b = gf( [1 1 0 1 0], 3, 11 );

[q, r ] = deconv(a,b) % deconvolution is equivalent to division
