/* 
com todos m primos entre si, a equação :

x= a1 mod m1
x = a2 mod m2
x = a3 mod m3
x = an mod mn

é resolvida por x0 = a1*X1*inv_mod_m1(X1) + ... + an*Xn*inv_mod_mn(Xn);
sendo Xk = (m1*m2*m3*...*mk*...*mn)/mk
ou seja, Xk é um número divisível por todos m menos por mk, e por isso 
a expressão resolve. Mais mastigado que isso é com o leitor kkkkkkkk

x_geral = x0 + k(m1*m2*m3*...*mn),    k inteiro

*/