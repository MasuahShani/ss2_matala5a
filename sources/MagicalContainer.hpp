#pragma once

#include <iostream>
using namespace std;
namespace ariel{
	


	class MagicalContainer
	{
	private:
		struct node {
			int val=0;
			node* next=nullptr;
			node(int val, node* next)
				: val(val), next(next) {
			}
		};
		node* arr;
		int p_size;
	public:
		MagicalContainer():arr(nullptr),p_size(0){}
		MagicalContainer(const MagicalContainer& mcl):arr(nullptr),p_size(0){}
		~MagicalContainer(){}//delete[] arr
		MagicalContainer& operator=(const MagicalContainer& mcl)
		{
			if(this==&mcl)
			{
				throw runtime_error("self assignment");
			}
			return *this;
		}
		MagicalContainer(MagicalContainer&& mcl) noexcept:arr(nullptr),p_size(0){}
		MagicalContainer & operator=(MagicalContainer&& mcl) noexcept {return *this;}

		void addElement(int val){}
		void removeElement(int val){}
		int size() const {return p_size;}


		class AscendingIterator {

		private:
			node* pointer;

		public:

			AscendingIterator(MagicalContainer &mcl)
				: pointer(mcl.arr) {
					
			}

			
			int& operator*() const {
				if (pointer == nullptr) {
					throw runtime_error("Dereferencing iterator pointing to an empty container");
				}
				return pointer->val;
			}

			// ++i;
			AscendingIterator& operator++() 
			{
				
				//*pointer =*(pointer+1) ;
				return *this;
			}

			bool operator==(const AscendingIterator& rhs) const {
				return pointer == rhs.pointer;
			}

			bool operator!=(const AscendingIterator& rhs) const {
				return pointer != rhs.pointer;
			}

			bool operator>(const AscendingIterator& rhs) const {
				return pointer > rhs.pointer;
			}

			bool operator<(const AscendingIterator& rhs) const {
				return pointer < rhs.pointer;
			}

			AscendingIterator begin(){return AscendingIterator(*this);}
			AscendingIterator end(){return AscendingIterator(*this);}
			
		};
		
		class SideCrossIterator {

		private:
			node* pointer;

		public:

			SideCrossIterator(MagicalContainer &mcl)
				: pointer(mcl.arr) {
			}

			
			
			int& operator*() const {
				if (pointer == nullptr) {
					throw runtime_error("Dereferencing iterator pointing to an empty container");
				}
				return pointer->val;
			}
			

			// ++i;
			SideCrossIterator& operator++() 
			{
				
				//*pointer =*(pointer+1) ;
				return *this;
			}

			bool operator==(const SideCrossIterator& rhs) const {
				return pointer == rhs.pointer;
			}

			bool operator!=(const SideCrossIterator& rhs) const {
				return pointer != rhs.pointer;
			}

			bool operator>(const SideCrossIterator& rhs) const {
				return pointer > rhs.pointer;
			}

			bool operator<(const SideCrossIterator& rhs) const {
				return pointer < rhs.pointer;
			}

			SideCrossIterator begin(){return *this;}
			SideCrossIterator end(){return *(this);}
			
		};
		class PrimeIterator {

		private:
			node* pointer;

		public:

			PrimeIterator(MagicalContainer &mcl)
				: pointer(mcl.arr) {
			}

			
			int& operator*() const {
				if (pointer == nullptr) {
					throw runtime_error("Dereferencing iterator pointing to an empty container");
				}
				return pointer->val;
			}

			// ++i;
			PrimeIterator& operator++() 
			{
				
				//*pointer =*(pointer+1) ;
				return *this;
			}

			bool operator==(const PrimeIterator& rhs) const {
				return pointer == rhs.pointer;
			}

			bool operator!=(const PrimeIterator& rhs) const {
				return pointer != rhs.pointer;
			}

			bool operator>(const PrimeIterator& rhs) const {
				return pointer > rhs.pointer;
			}

			bool operator<(const PrimeIterator& rhs) const {
				return pointer < rhs.pointer;
			}

			PrimeIterator begin(){return *this;}
			PrimeIterator end(){return *(this);}
			
		};
	};
}



