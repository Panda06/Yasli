#ifndef YASLI_HPP
#define YASLI_HPP
namespace yasli
{
	// TODO: add Exception
	template <class ArchiveType>
	class Output
	{
	public:
		Output(ArchiveType * const pointer) : pointArchive(pointer) {}
		
		template<class T>
		ArchiveType & operator()(T && arg)
		{
			serialize(std::forward<T>(arg));
			return *pointArchive;
		}
		template<class T>
		ArchiveType & operator<< (T && arg)
		{
			serialize(std::forward<T> (arg));
			return *pointArchive;
		}
	private:
		ArchiveType * const pointArchive;
		void serialize(ArchiveType *);
		template <class T>
		void serialize(T && arg)
		{
			save(*pointArchive, arg);
		}
	};

	template <class ArchiveType>
	class Input
	{
		public:
		Input(ArchiveType * const pointer) : pointAr�hive(pointer) {}
		template<class T>
		ArchiveType & operator()(T && arg)
		{
			serialize(std::forward<T> (arg));
			return *pointArchive;
		}
		template<class T>
		ArchiveType & operator>> (T && arg)
		{
			serialize(std::forward<T>(arg));
			return *pointAr�hive;
		}
	private:
		ArchiveType * const pointAr�hive;
		void serialize(ArchiveType *);
		template <class T>
		void serialize(T && arg)
		{
			load(*pointAr�hive, arg);
		}
	};
}
#endif // !YASLI_HPP
