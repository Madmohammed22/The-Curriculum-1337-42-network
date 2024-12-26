/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyAwesomePhoneBook.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:13:57 by mohammedmad       #+#    #+#             */
/*   Updated: 2024/10/24 15:56:10 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MyAwesomePhoneBook.hpp"

Contact::Contact() : name("default"), lastName("default"), nickname("default"), number("default"), darkestSecret("default") {}
Contact::Contact(const std::string name, const std::string lastName, const std::string nickname,
                 const std::string number, const std::string darkestSecret) : name(name), lastName(lastName),
                                                                              nickname(nickname), number(number), darkestSecret(darkestSecret) {}
std::string Contact::get_name() const
{
    return name;
}
std::string Contact::get_lastName() const
{
    if (lastName.length() > 10)
        return lastName.substr(0, 9) + ".";
    if (lastName.length() < 10)
    {
        std::string temp = lastName;
        return temp.append(10 - temp.length(), ' ');
    }
    return lastName;
}
std::string Contact::get_nickname() const
{
    if (nickname.length() > 10)
        return nickname.substr(0, 9) + ".";
    if (nickname.length() < 10)
    {
        std::string temp = nickname;
        return temp.append(10 - temp.length(), ' ');
    }
    return nickname;
}
std::string Contact::get_number() const
{
    return number;
}
std::string Contact::get_darkestSecret() const
{
    if (darkestSecret.length() > 10)
        return darkestSecret.substr(0, 9) + ".";
    if (darkestSecret.length() < 10)
    {
        std::string temp = darkestSecret;
        return temp.append(10 - temp.length(), ' ');
    }
    return darkestSecret;
}

PhoneBook::PhoneBook()
{
    for (int i = 0; i < SIZEOFCONTACT; i++)
    {
        contact[i] = Contact();
    }
}

void PhoneBook::printContacts() const
{
    for (int i = 0; i < SIZEOFCONTACT; i++)
    {
        std::cout << contact[i].get_name() << std::endl;
        std ::cout << contact[i].get_lastName() << std::endl;
        std ::cout << contact[i].get_nickname() << std::endl;
        std ::cout << contact[i].get_number() << std::endl;
        std ::cout << contact[i].get_darkestSecret() << std::endl;
    }
}

int main()
{
    PhoneBook phoneBook;
    std::string check;
    while (1)
    {
        std::cout << "Choose number: ADD [1] | SEARCH [2] | EXIT [3]" << std::endl;
        std::cout << "Enter Command: ";
        getline(cin, check);
        if (std::cin.eof())
            break;
        if (check == "1")
        {
            std::string name, lastName, nickname, number, darkestSecret;
            std::cout << "Enter Name: ";
            getline(cin, name);
            if (name.empty())
                break;
            std::cout << "Enter Last Name: ";
            getline(cin, lastName);
            if (lastName.empty())
                break;
            std::cout << "Enter Nickname: ";
            getline(cin, nickname);
            if (nickname.empty())
                break;
            std::cout << "Enter Number: ";
            getline(cin, number);
            if (number.empty())
                break;
            if (number.size() != 10 || (number.find_first_not_of("0123456789") != std::string::npos))
            {
                std::cout << "Invalid Number" << std::endl;
                continue;
            }
            std::cout << "Enter Darkest Secret: ";
            getline(cin, darkestSecret);

            for (int i = 0; i < SIZEOFCONTACT; i++)
            {
                if (phoneBook.contact[i].get_name() == "default")
                {
                    phoneBook.contact[i] = Contact(name, lastName, nickname, number, darkestSecret);
                    std::cout << "Contact Added" << std::ends;
                    break;
                }
                if (i == SIZEOFCONTACT - 1)
                {
                    phoneBook.contact[0] = Contact(name, lastName, nickname, number, darkestSecret);
                    std ::cin.clear();
                }
            }
        }
        else if (check == "2")
        {
            std::cout << "Enter Name to Search: ";
            getline(cin, check);
            bool found = false;
            for (int i = 0; i < SIZEOFCONTACT; i++)
            {
                if (check == phoneBook.contact[i].get_name())
                {
                    std ::string name = phoneBook.contact[i].get_name();
                    if (name.length() < 10)
                    {
                        std::string temp = name;
                        name = temp.append(10 - temp.length(), ' ');
                    }
                    if (name.length() > 10)
                        name = name.substr(0, 9) + ".";
                    std ::string lastName = phoneBook.contact[i].get_lastName();
                    std ::string nickname = phoneBook.contact[i].get_nickname();
                    std::cout << "Contact Found: " << std::endl;
                    std ::cout << "---------------------------------------------" << std::endl;
                    std ::cout << "|index     |first name|Last Name |nickname  |" << std::endl;
                    std ::cout << "---------------------------------------------" << std::endl;
                    std ::cout << "|" << i << "         |" << name << "|" << lastName << "|" << nickname << "|" << std::endl;
                    std ::cout << "---------------------------------------------" << std::endl;
                    found = true;
                    break;
                }
            }
            if (!found)
                std::cout << "Contact Not Found" << std::endl;
        }
        else if (check == "3")
            break;
        else
        {
            std::cout << "Invalid Command" << std::endl;
            std ::cin.clear();
        }
        std ::cout << std ::endl;
        std ::cin.clear();
    }
    return EXIT_SUCCESS;
}
