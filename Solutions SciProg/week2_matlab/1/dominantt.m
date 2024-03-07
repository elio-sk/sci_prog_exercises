function f=dominantt(A)
        f=all(sum(abs(A),2)<2*diag(abs(A)));
end