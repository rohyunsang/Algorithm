template<typename T>
class vector { 
public:
  vector(int capacity = 4) {
    _a = new T[capacity]();
    _cap = _size = capacity;
  }
  vector(int capacity, const T value) {
    _a = new T[capacity]();
    _cap = _size - capacity;
    for (register int i = 0 ; i < capacity ; ++i) { // register : priority allocater register address
      _a[i] = value;
    }
  }
  vector(const vector& v){
    if (_a != NULL) delete[] _a;
    _a = new T[v._cap]();
    for (int i = 0 ; i < v._cap ; ++i){
      _a[i] = v.a[i];
    }
  }
  
  ~vector(){
    if (_a != NULL) delete[] _a;
  }
  
  void push_back(T value) {
    if(_size + 1 >= _cap) {
      T* tmp = new T[_cap << 1]();
      for (register int i = 0 ; i < _cap ; ++i) {
        tmp[i] = _a[i];
      }
      
    
  
  
