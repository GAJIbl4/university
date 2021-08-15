type
  Ar = array [1 .. 50] of real;

procedure DataIn(Xn, Dx: real; K: integer; var X: Ar);
var
  I: integer;
begin
  X[1] := Xn;
  for I := 2 to K do
  begin
    X[I] := X[I - 1] + Dx;
  end;
end;

procedure Series(X1, Eps, R, A: real; Km: integer; var S1: real);
var
  I: integer;
begin
  S1 := 0;
  R := 1;
  I := 1;
  repeat
  begin
    S1 := S1 + R;
    R := R * ((X1 + A) / I);
    if (abs(R) < Eps) then
      I := Km
    else
      I := I + 1;
  end;
  until I >= Km;
end;

procedure DataOut(X, S: Ar; K: integer; A: real);
var
  I: integer;
begin
  writeln('A=', A);
  for I := 1 to K do
  begin
    writeln('X[', I, ']=', X[I], '   Sum=', S[I]);
  end;
end;

var
  X, S: Ar;
  Eps, R, A, Xn, Dx: real;
  Km, K, I: integer;

begin
  Eps := 0.0001;    //Погрешность
  Km := 50;         //Количество итераций
  A := 1;           //Параметр А
  Xn := 0;          //Начальное значение X
  Dx := 1;          //Шаг X
  K := 5;           //Количество X

  DataIn(Xn, Dx, K, X);
  for I := 1 to K do
    Series(X[I], Eps, R, A, Km, S[I]);
  DataOut(X, S, K, A);
end.