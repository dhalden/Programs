for i=1:5
    k = 13; N = 52; n = 5; y = i;
    P(i) = (nchoosek(k, y)*nchoosek(N-k, n-y))/(nchoosek(N,n));
    E(i) = P(i)*i;
end