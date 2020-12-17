template<class I, class R>
ResourceHolder<I, R>::ResourceHolder() : m_resources{}
{
}

template<class I, class R>
R& ResourceHolder<I, R>::operator[](const I& id)
{
	return *m_resources.at(id);
}

template<class I, class R>
const R& ResourceHolder<I, R>::operator[](const I& id) const
{
	return *m_resources.at(id);
}
