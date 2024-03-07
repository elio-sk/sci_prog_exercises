function n=p_norm(v,p)
if(1<=p<inf)
    n=(sum(abs(v).^p))^(1/p);
else
    fprintf("Input p accordingly.")
end