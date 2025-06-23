// Anotações importantes sobre módulo e expressões modulares;
// a = b (mod m); <-> a + (k*m) = b + (t*m), k e t sendo inteiros;
// -x (mod m) = - x + m (mod m);
// (a/b) (mod m) != (a (mod m) / b (mod m)) mod m 
//      a/b (mod m) = (a (mod m)) * b_inverso (mod m)
//      gcd(m,b) = 1, b_inverso = b^(phi(m)-1)  [ver EulerTotient.cpp];
//      se m é primo, phi(m) = m-1, b_inverso = b^(m-2);
