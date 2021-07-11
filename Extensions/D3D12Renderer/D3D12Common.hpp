#ifndef D3D12RS_COMMON_HPP
#define D3D12RS_COMMON_HPP

#ifdef COWDIA_PLATFORM_WIN32
#define COWDIA_D3D12_API __declspec(dllexport)
#else
#define COWDIA_D3D12_API
#endif

namespace Cowdia::Core
{
template <class T>
class ComPtr final
{
 public:
    //! Default constructor.
    ComPtr() = default;

    //! Constructor with a pointer.
    ComPtr(T* ptr) : ptr_(ptr)
    {
        addRef();
    }

    //! Copy constructor.
    ComPtr(const ComPtr<T>& other) : ptr_(other.ptr_)
    {
        addRef();
    }

    //! Destructor.
    ~ComPtr() noexcept
    {
        release();
    }

    //! Assignment operator.
    ComPtr<T>& operator=(T* other)
    {
        if (other != ptr_)
        {
            release();

            ptr_ = other;

            addRef();
        }

        return *this;
    }

    //! Copy assignment operator.
    ComPtr<T>& operator=(const ComPtr<T>& other)
    {
        if (other.ptr_ != ptr_)
        {
            release();

            ptr_ = other.ptr_;

            addRef();
        }

        return *this;
    }

    void Reset()
    {
        release();
    }

    operator bool() const
    {
        return ptr_ != nullptr;
    }

    T* Get() const
    {
        return ptr_;
    }

    T** GetAddressOf()
    {
        return &ptr_;
    }

    T** ReleaseAndGetAddressOf()
    {
        release();
        return &ptr_;
    }

    void Attach(T* other)
    {
        release();

        ptr_ = other;
    }

    T* Detach()
    {
        T* tmp = ptr_;

        ptr_ = 0;

        return tmp;
    }

    T* operator->() const
    {
        return ptr_;
    }

    bool operator==(const ComPtr<T>& other) const
    {
        return ptr_ == other.ptr_;
    }

    bool operator!=(const ComPtr<T>& other) const
    {
        return !(*this == other);
    }

 private:
    void addRef()
    {
        if (ptr_)
            ptr_->AddRef();
    }

    void release()
    {
        if (ptr_)
        {
            ptr_->Release();
            ptr_ = nullptr;
        }
    }

 private:
    T* ptr_{ nullptr };
};
}  // namespace Cowdia::Core

#endif  // D3D12RS_COMMON_HPP
