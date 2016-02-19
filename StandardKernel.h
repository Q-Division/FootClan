#ifndef STANDARDKERNEL_H
#define STANDARDKERNEL_H

//#include "IKernel.h"
#include "Factory.h"
#include <map>
#include <typeindex>

using namespace std;

namespace FootClan
{
	class StandardKernel //: public IKernel
	{
	private:
		map<type_index, shared_ptr<IFactory>> mMap;

	public:
		//--- Constructor ---
		StandardKernel()
		{

		}

		//--- Destructor ---
		virtual ~StandardKernel()
		{

		}

		template<class IType, class BType>
		void Bind()
		{
			mMap[type_index(typeid(IType))] = make_shared<Factory<BType>>();
		}

		template<class IType>
		shared_ptr<IType> Get()
		{
			shared_ptr<IFactory> factory = mMap.find(type_index(typeid(IType)))->second;

			void* object = factory->Create();
			IType* typedobj = (IType*)object;

			return shared_ptr<IType>(typedobj);
		}
	};
}

#endif //STANDARDKERNEL_H