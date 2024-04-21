with Interfaces.C; use Interfaces.C;

package Library_Rec is

   type Diofantic_Result is record
      X : Integer;
      Y : Integer;
   end record
     with Convention => C;

   function Factorial(N : Integer) return Integer
     with Import, Convention => C;

   function NWD(A, B : Integer) return Integer
     with Import, Convention => C;

   function Diofantic(A, B, C : Integer) return Diofantic_Result
     with Import, Convention => C;

end Library_Rec;