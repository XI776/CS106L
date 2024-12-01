#include "user.h"

/**
 * Creates a new User with the given name and no friends.
 */
User::User(const std::string& name)
  : _name(name)
  , _friends(nullptr)
  , _size(0)
  , _capacity(0)
{
}

User::~User()
{
  delete[] _friends;
  _friends = nullptr;
}

User::User(const User &user)
{
  if(this == &user)
    ;
  
  _friends = new std::string[user._capacity];
  _name = user.get_name();
  _capacity = user._capacity;
  _size = user.size();
  for(size_t i = 0;i<_size ; i++)
  {
    _friends[i] = user._friends[i];
  }
}

/**
 * Adds a friend to this User's list of friends.
 * @param name The name of the friend to add.
 */
void
User::add_friend(const std::string& name)
{
  if (_size == _capacity) {
    _capacity = 2 * _capacity + 1;
    std::string* newFriends = new std::string[_capacity];
    for (size_t i = 0; i < _size; ++i) {
      newFriends[i] = _friends[i];
    }
    delete[] _friends;
    _friends = newFriends;
  }

  _friends[_size++] = name;
}

/**
 * Returns the name of this User.
 */
std::string
User::get_name() const
{
  return _name;
}

/**
 * Returns the number of friends this User has.
 */
size_t
User::size() const
{
  return _size;
}

/**
 * Sets the friend at the given index to the given name.
 * @param index The index of the friend to set.
 * @param name The name to set the friend to.
 */
void User::set_friend(size_t index, const std::string& name)
{
  _friends[index] = name;
}

User &User::operator=(const User &user)
{
    // TODO: 在此处插入 return 语句
    if(this == &user) 
      return *this;


    std::string* newFriend = new std::string[user._capacity];
    _capacity = user._capacity;
    _name = user._name;
    _size = user._size;
    std::copy(user._friends->begin(), user._friends->end(), newFriend);

    delete[] _friends;

    _friends = newFriend;    
    return *this;
}

/** 
 * STUDENT TODO:
 * The definitions for your custom operators and special member functions will go here!
 */

std::ostream & operator<<(std::ostream &os, const User & user) 
{
    // TODO: 在此处插入 return 语句
    os<<"User(name="<<user.get_name()<<", friends=[";
    os<<user._friends[0];
    for(size_t i = 1;i < user.size(); i++){
      os<<", "<<user._friends[i];
    }
    os<<"])";
    return os;
}

User& User::operator+= (User &user)
{
  if(this == &user) 
      return *this;
  this->add_friend(user._name);

  user.add_friend(this->_name);
  
  return *this;
}

void  User::operator<(const User &user)
{
    if(_name < user.get_name())
      std::cout << this->get_name() << " is less than " << user.get_name() <<std::endl;
    else  std::cout << user.get_name() << " is less than " << _name << std::endl;
}
