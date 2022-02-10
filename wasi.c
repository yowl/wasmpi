#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 int emscripten_get_callstack(int flags, char* buf, int maxbytes)
{
    *buf = 0;
    return 0;
}

int __cxa_thread_atexit(void (*func)(), void *obj, void *dso_symbol)
{
	return 0;
}

int pthread_create(int sig, int i, int j, void (*func)(int))
{
	return 0;
}

void* pthread_self(void)
{
	return 0;
}

int pthread_equal(void* t1, void* t2)
{
	return 1;
}

int __errno_location()
{
	return 0;
}

int pthread_condattr_destroy(void* attr)
{
	return 0;
}

int pthread_condattr_init(void* attr)
{
	return 0;
}

int pthread_condattr_setclock(void* attr, void* clock_id)
{
	return 0;
}

int pthread_mutex_init(void* restrict mutex, const void* restrict attr)
{
	return 0;
}

int pthread_cond_init(void* restrict cond,const void* restrict attr)
{
	return 0;
}

int pthread_mutex_destroy(void* mutex)
{
	return 0;
}

int pthread_attr_init(void* attr)
{
	return 0;
}

int pthread_attr_destroy(void* attr)
{
	return 0;
}

int pthread_attr_setdetachstate(void* attrint, int x)
{
	return 0;
}

int pthread_mutex_lock(void* mutex)
{
	return 0;
}

int pthread_mutex_unlock(void* mutex)
{
	return 0;
}
int pthread_cond_broadcast(void* cond)
{
	return 0;
}

int pthread_cond_timedwait(void* restrict cond,	void* restrict mutex, const void* restrict abstime)
{
	return 0;
}
int pthread_cond_wait(void* restrict cond,void* restrict mutex)
{
	return 0;
}

int pthread_cond_destroy(void* cond)
{
	return 0;
}

int mprotect(void* addr, size_t len, int prot)
{
	return 0;
}

int pthread_getattr_np(void* thread, void* attr)
{
	return 0;
}

void* dlopen(const char* filename, int flag)
{
	return NULL;
}

char* dlerror(void)
{
	return NULL;
}

void* dlsym(void* handle, const char* symbol)
{
	return NULL;
}

int pthread_attr_getstack(void* attr, void** stackaddr, size_t* stacksize)
{
	return 0;
}

int mlock(const void* addr, size_t len)
{
	return 0;
}

int munlock(const void* addr, size_t len)
{
	return 0;
}

int posix_madvise(void* addr, size_t len, int advice)
{
	return 0;
}

int pthread_mutexattr_destroy(void* attr)
{
	return 0;
}

int pthread_mutexattr_init(void* attr)
{
	return 0;
}

int pthread_mutexattr_settype(void* attr, int type)
{
	return 0;
}

#define RLIM_INFINITY (~0UL) // In WASI SDK this is a long long, but we'll match emscripten to avoid a warning
unsigned long getrlimit(int resource, void* rlim)
{
	return RLIM_INFINITY;
}

void* __cxa_allocate_exception(size_t thrown_size)
{
	return NULL;
}

void __cxa_throw(void* thrown_exception, void* tinfo, void (*dest)(void*))
{
}

int readdir_r(void* dirp, void* entry, void** result)
{
	return 0;
}

int flock(int fd, int operation)
{
	return 0;
}

int fstatfs(int fd, void* buf)
{
	return 0;
}

void syslog(int priority, void* format, ...)
{
}

int pthread_cond_signal(void* cond)
{
	return 0;
}

int getrusage(int who, void* usage)
{
	return 0;
}

int dlclose(void* handle)
{
	return 0;
}

int signal(int sig, void (*func)(int))
{
	return 0;
}

int gai_strerror(int sig )
{
	return 0;
}

// mmap2() Overrides the weak alias that Emscripten defines which returns ENOSYS
// This is only used from GCToOSInterface::Initialize
long mmap(long addr, long len, long prot, long flags, long fd, long long off) {
	
	void* alignedAddress;

	if (addr == 0)
	{
		// alignment must match OS_PAGE_SIZE or GCToOSInterface::Initialize will fail
		if (posix_memalign(&alignedAddress, len, 65536) != 0)
		{
			return -1; // failed
		}
	}

	memset(alignedAddress, 0, len);
	return (long)alignedAddress;
}

int dotnet_browser_entropy(char* buf, int size)
{
	return 0;
}
