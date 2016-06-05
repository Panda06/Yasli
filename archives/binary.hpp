#ifndef ARCHIVES_BINARY_HPP
#define ARCHIVES_BINARY_HPP
#include <yasli/yasli.hpp>

#include <sstream>
namespace yasli
{
	class BinaryOutput : public Output<BinaryOutput>
	{
	public:
		BinaryOutput(std::ostream & Stream): outStream(Stream), Output<BinaryOutput>(this)
		{ }
		void save_Data(const void * data, std::size_t size)
		{
			
			//if (size !=
				((outStream.rdbuf()->sputn(reinterpret_cast<const char*>(data), size)));
				//)
				// add Exception if size != written size
			
		}

	private:
		std::ostream & outStream;
	};

	class BinaryInput : public Input<BinaryInput>
	{
	public:
		BinaryInput(std::istream & Stream) : inStream(Stream), Input<BinaryInput>(this)
		{}
		
		void load_Data(void * data, std::size_t size)
		{
			inStream.rdbuf()->sgetn(reinterpret_cast<char*>(data), size);
		}
	private:
		std::istream & inStream;
	};

	template<class T> inline
	std::enable_if_t<std::is_arithmetic<T>::value, void>
    save(BinaryOutput & a, T const & t)
	{
		a.save_Data(std::addressof(t), sizeof(t));
	}
	template<class T>
	std::enable_if_t<std::is_arithmetic<T>::value, void>
	load(BinaryInput & a, T & t)
	{
		a.load_Data(std::addressof(t), sizeof(t));
	}
}
#endif // !ARCHIVES_BINARY_HPP
