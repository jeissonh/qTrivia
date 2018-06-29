#ifndef COMMON_H
#define COMMON_H

#define DISABLE_COPY_CLASS(Class) \
	Class(const Class& other) = delete; \
	Class(Class&& other) = delete; \
	Class& operator=(const Class& other) = delete; \
	Class& operator=(Class&& other) = delete



#endif // COMMON_H
