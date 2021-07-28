#ifndef ARRAYINT_H_INCLUDED
#define ARRAYINT_H_INCLUDED

#include <cassert>

class ArrayInt
{
private:
    int m_length;
    int *m_data;

public:
    ArrayInt(): m_length(0), m_data(nullptr)
    { }

    ArrayInt(int length):
    m_length(length)
    {
        assert(length >= 0);

        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }

    ~ArrayInt()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;

        m_data = nullptr;
        m_length = 0;
    }
    int getLength() { return m_length; }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    void resize(int newLength)
    {
        if (newLength == m_length)
            return;

        if (newLength <= 0)
        {
            erase();
            return;
        }

        int *data = new int[newLength];

        if (m_length > 0)
        {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;

            for (int index=0; index < elementsToCopy ; ++index)
                data[index] = m_data[index];
        }

        delete[] m_data;

        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index)
    {
        assert(index >= 0 && index <= m_length);

        int *data = new int[m_length+1];

        for (int before=0; before < index; ++before)
            data[before] = m_data[before];

        data [index] = value;

        for (int after=index; after < m_length; ++after)
            data[after+1] = m_data[after];

        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    void push_back(int value) { insertBefore(value, m_length); }
// First Task
    void pop_back(){
        int NewLength;
        NewLength = m_length;
        resize((NewLength - 1));
    }

    void pop_front(){
        int NewLength;
        NewLength = m_length;
        for(int i = 0; i < m_length; i++){
            m_data[i] = m_data[i + 1];
        }
        resize((NewLength - 1));
    }

    void sort(){
        int temp;
        for(int i = 0; i < m_length; i++){
            for(int j = 0; j < m_length; j++){
                if(m_data[j] < m_data[j + 1]){
                    while(!m_data[m_length])
                        temp = m_data[j + 1];
                        m_data[j + 1] = m_data[j];
                        m_data[j] = temp;
                }else break;
            }
        }
    }

    void printarr(){
        for(int i = 0; i < m_length; i++){
            std::cout << m_data[i] << " ";
        }
        std::cout << std::endl;
    }
    void printelem(){
        int idx;
        std::cout << "The array consist of " << sizeof(m_data)<< " elements." << std::endl;
        std::cout << "Which element do you want to see?";
        std::cin >> idx;
    }
};


#endif // ARRAYINT_H_INCLUDED
