#pragma once
#include <map>
#include <memory>

template <class I, class R>
class ResourceHolder
{
public:
	ResourceHolder();
	R& operator[](I id);
	const R& operator[](I id) const;

protected:
	std::map<I, std::unique_ptr<R>> m_resources;
};

#include "ResourceHolder.inl"
