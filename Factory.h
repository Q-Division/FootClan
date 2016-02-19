#ifndef FACTORY_H
#define FACTORY_H

#include <memory>

using namespace std;

namespace FootClan
{
	class IFactory
	{
	public:
		virtual ~IFactory() {}

		virtual void* Create() = 0;
	};

	template<class T>
	class Factory : public IFactory
	{
	public:
		//--- Constructor ---
		Factory()
		{

		}

		//--- Destructor ---
		virtual ~Factory()
		{

		}

		virtual void* Create() override
		{
			return static_cast<void*>(new T());
		}
	};
}

#endif //FACTORY_H