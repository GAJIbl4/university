uses CRT;

const
  Nmax = 40;

Type
  Tmy = array [1 .. Nmax, 1 .. Nmax] of real;
  Tma = array [1 .. Nmax] of real;
  Ter = array [1 .. Nmax, 1 .. Nmax] of boolean;

procedure Equat(C, D, Eps: real; Km: integer; var B, Bt: real;
  var Err: integer);

  Function F(X: real): real;
  begin
    if X=0 then X:=2E-38;
    F := 2*ln(X)-1/power(X,2);
  end;

var
  I: integer;

begin
  Err := 1;
  I := 1;
  while I <= Km do
  begin
    B := (C + D) / 2;
    if abs(F(B)) > Eps then
    begin
      if F(C) * F(B) > 0 then
        C := B
      else
        D := B;
    end
    else
    begin
      I := Km;
      Err := 0;
    end;
    I := I + 1;
  end;
  Bt := abs(F(B));
end;

procedure Tab(B: real; M, N: integer; Ma, Mx: Tma; var My: Tmy; var Er: Ter);

var
  I, J: integer;
  A, X: real;
begin
  for I := 1 to M do
    for j := 1 to N do
        if (Ma[I] = 0) or ((power(Ma[I],2)+power(B,2))<=0) then
          Er[j, I] := true
        else
          Er[j, I] := false;

  For I := 1 to M do
  begin
    A := Ma[I];
    For j := 1 to N do
    begin
      X := Mx[j];
      if (Er[j, I] = false) then
          My[j, I] := B/(A*sqrt(power(A,2)+power(B,2)))*arctan(A*X/(sqrt(power(A,2)+power(B,2))));
    end;
  end;
end;

procedure DataIn(Xn, Dx, Xk: real; M: integer; var Ma, Mx: Tma; var N:integer);

var
  I: integer;
begin
  for I := 1 to M do
  begin
    write('A[',I,']=');
    readln(Ma[I]);
  end;

  Mx[1] := Xn;
  N:=floor((Xk - Xn) / Dx) + 1;
  for I:=2 to N do 
  Mx[I] := Mx[I - 1] + Dx;
   
end;

procedure DataOut(M, N: integer; B, Bt: real; Ma, Mx: Tma; My: Tmy;

  Er: Ter);
var
  I, j: integer;
begin
    write('Корень уравнения: ');
    writeln(B:10:9);
    write('Погрешность по невязке: ');
    writeln(Bt:10:9);

    write('         ');
    for J := 1 to N do
    begin
      write('X[',J,']=',Mx[J]:2:1,' ');
    end;
    writeln;
    for I := 1 to M do
    begin
    write('A[',I,']=',Ma[I]:2:1,' ');
      for J := 1 to N do
        begin
        write(My[J,I]:7:3,'  ');
        end;
    writeln;
    end;
end;


var
  Ma, Mx: Tma;
  My: Tmy;
  Er: Ter;
  Xn, Dx, Xk, B, Bt, Eps, C, D: real;
  Km, M, N, Err: integer;
begin
  write('Xn=');
  readln(Xn);
  write('Dx=');
  readln(Dx);
  write('Xk=');
  readln(Xk);
  write('M=');
  readln(M);
  DataIn(Xn, Dx, Xk, M, Ma, Mx, N);
  write('C=');
  readln(C);
  write('D=');
  readln(D);
  write('Eps=');
  readln(Eps);
  write('Km=');
  readln(Km);
  

  Equat(C, D, Eps, Km, B, Bt, Err);
  if Err = 0 then
  begin
    Tab(B, M, N, Ma, Mx, My, Er);
    DataOut(M, N, B, Bt, Ma, Mx, My, Er);
  end
  else
    writeln('Нужно больше итераций!!!');
    readln;
end.