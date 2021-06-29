#ifndef COWDIA_SINGLETON_HPP
#define COWDIA_SINGLETON_HPP

#include <cassert>

namespace Cowdia::Utils
{
template <class T>
class Singleton
{
 public:
    //! Default constrcutor.
    Singleton()
    {
        assert(instance_ == nullptr);
        instance_ = reinterpret_cast<T*>(this);
    }

    //! Default destructor.
    virtual ~Singleton() = default;

    //! Delete copy cosntructor.
    Singleton(const Singleton&) = delete;

    //! Delete move constructor.
    Singleton(Singleton&&) = delete;

    //! Delete copy assignment operator.
    Singleton& operator=(const Singleton&) = delete;

    //! Delete move assignment operator.
    Singleton& operator=(Singleton&&) = delete;

    //! Returns instance.
    static T& Get()
    {
        return *instance_;
    }

 private:
    inline static T* instance_{ nullptr };
};
}  // namespace Cowdia::Utils

#endif  // COWDIA_SINGLETON_HPP
