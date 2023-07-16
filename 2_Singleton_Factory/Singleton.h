
#undef UNUSED
#undef DISALLOW_COPY_AND_ASSIGN

#define UNUSED(param) (void)param

// Delete copy constructor and copy assignment operator
#define DISALLOW_COPY_AND_ASSIGN(classname) \
  classname(const classname &) = delete;    \
  classname &operator=(const classname &) = delete;

// Singleton
#define DECLARE_SINGLETON(classname)                                      \
 public:                                                                  \
  static classname *getInstance() {                                       \
    static classname *instance = nullptr;                                 \
    if (!instance) {                                                      \
      static std::once_flag flag;                                         \
      std::call_once(flag,                                                \
                     [&] { instance = new (std::nothrow) classname(); }); \
    }                                                                     \
    return instance;                                                      \
  }                                                                       \
                                                                          \
                                                                          \
 private:                                                                 \
  classname();                                                            \
  DISALLOW_COPY_AND_ASSIGN(classname)
