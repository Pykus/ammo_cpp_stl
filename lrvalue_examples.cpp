class Widget {};
void func1(Widget pb); //passed by value
void func2(Widget &pb);//passed by lvalue reference
void func3(const Widget &pb);//passed by const reference (lvalue reference, const reference, rvalue reference)
void func4(Widget &&pb); //pass by rvalue reference
Widget x; //x is lvalue


func1(x); //ok - call with an lvalue
func2(x); //ok
func3(x); //ok
func4(x); //error function wants rvalue reference you pass lvalue

func1(Widget{});//ok- call with an rvalue
func2(Widget{});//error funcion wants lvalue reference you pass rvalue
func3(Widget{});//ok
func4(Widget{});//ok

Data type:
1) value (12,true,"text") +
2) operations (compare, assignment, what cac be done with data)
Expression:
1) data type+ (int, ptr, string, lvalue reference...)
2) value category (lvalue, rvalue)