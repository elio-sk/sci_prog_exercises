for i=2:50;
    A=eye(i);
    I=1:length(A);
    J=[1:length(A), i+1];
    a=ones(1,i);
    m=i;
    x0=ones(1,i);
    tol=1e-5;
    tic
    [la,y]=poweriteration(A,I,J,a,m,x0,tol);
    t_power(i-1)=toc;
    tic
    [V,D] = eig(A);
    t_eig(i-1)=toc;
end
plot([2:51],t_power,'r')
hold on
plot([2:51],t_eig,'b')
legend('t power','t eig')
%comment: big oscillations are visible because of 
%non-neutral conditions of cpu running
% and also the rand vector, instead fix it choose ones(1,i)



