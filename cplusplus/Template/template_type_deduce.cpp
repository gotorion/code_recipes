template<typename T>
void f(ParamType param)
{

}

// 1. ParamType is pointer/reference, not common reference
// if expr is reference, ignore ref then match T and ParamType
template<typename T>
void f(T& param);
int x = 27;
const int cx = x;
const int& rx = x;
f(x); // T is int
f(cx); // T is const int, param type is const int&
f(rx); // T is const int, param type is const int&
// 2. common ref
// must like this
template<typename T>
void f(T&& param);

// 3. value type
// this means param will be a new copy, thus all CV(const, valatile) will be ignored, so is reference
template<typename T>
void f(T param);
