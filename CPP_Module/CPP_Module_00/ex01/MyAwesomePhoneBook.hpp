/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyAwesomePhoneBook.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:00:49 by mohammedmad       #+#    #+#             */
/*   Updated: 2024/10/24 15:58:33 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYAWESOMEPHONEBOOK_HPP
#define MYAWESOMEPHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

#define SIZEOFCONTACT 8
using namespace std;

class Contact
{
private:
    std::string name, lastName, nickname, number, darkestSecret;

public:
    Contact();
    Contact(const std::string name, const std::string lastName, const std::string nickname,
            const std::string number, const std::string darkestSecret);
    std ::string get_name() const;
    std ::string get_lastName() const;
    std ::string get_nickname() const;
    std ::string get_number() const;
    std ::string get_darkestSecret() const;
};

class PhoneBook
{
public:
    Contact contact[SIZEOFCONTACT];

public:
    PhoneBook();

    void printContacts() const;
};

#endif