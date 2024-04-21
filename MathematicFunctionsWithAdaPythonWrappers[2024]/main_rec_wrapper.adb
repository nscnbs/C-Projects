--gnatmake -o wrapper main_rec_wrapper.adb
--gcc -c library_rec.c
--gnatmake -o wrapper main_rec_wrapper.adb


with Ada.Text_IO; use Ada.Text_IO;
with Library_Rec; use Library_Rec;

procedure Main_Rec_Wrapper is
   A, B, C : Integer;
   Result : Diofantic_Result;
begin
   Put_Line("ADA WRAPPER C REKURSJA");

   -- Factorial
   Put_Line("5! = " & Integer'Image(Factorial(5)));

   -- NWD
   Put_Line("NWD: 36 i 48 = " & Integer'Image(NWD(36, 48)));

   -- Diofantic
   A := 120;
   B := 144;
   C := 72;
   Result := Diofantic(A, B, C);

   if Result.X /= -1 and Result.Y /= -1 then
      Put_Line("Rozwiązanie równania " & Integer'Image(A) & "x + " & Integer'Image(B) & "y = " & Integer'Image(C) & " to x = " & Integer'Image(Result.X) & ", y = " & Integer'Image(Result.Y));
   else
      Put_Line("Brak rozwiązania dla równania " & Integer'Image(A) & "x + " & Integer'Image(B) & "y = " & Integer'Image(C));
   end if;
end Main_Rec_Wrapper;