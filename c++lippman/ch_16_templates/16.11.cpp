/*
Exercise 16.11: The following definition of List is incorrect. How would you fix it?
*/

// template <typename elemType> class ListItem;

// template <typename elemType> class List {
// public:
//     List<elemType>();
//     List<elemType>(const List<elemType> &);
//     List<elemType>& operator=(const List<elemType> &);
//     ~List();
//     void insert(ListItem *ptr, elemType value);
// private:
//     ListItem *front, *end;
// };

/*
Answer: 
- instantiate ListItem
- 
*/

template <typename elemType> class ListItem;

template <typename elemType> class List {
public:
    List<elemType>();
    List<elemType>(const List<elemType> &);
    List<elemType>& operator=(const List<elemType> &);
    ~List();
    void insert(ListItem<elemType> *ptr, elemType value);
private:
    ListItem<elemType> *front, *end;
};
