/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>

std::string kYourName = "S Y"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::unordered_set<std::string> get_applicants(std::string filename) {
  // STUDENT TODO: Implement this function.
  std::ifstream ifs(filename);
  std::unordered_set<std::string> name_set;
  std::string line;
  while (std::getline(ifs, line) && !line.empty()) {
    name_set.insert(line);

  }
  // for (auto it : name_set) {
  //   std::cout << it << '\n';
  // }
  return name_set;
}


bool isSame(const std::string& name1, const std::string& name2) {
  if (name1[0] == name2[0]) {
    size_t pos1 = name1.find(" ") ;
    size_t pos2 = name2.find(" ") ;
    return name1[++pos1] == name2[++pos2];
  }
  return false;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::unordered_set<std::string>& students) {
  // STUDENT TODO: Implement this function.
  std::queue<const std::string *> q;
  for (auto n = students.begin(); n != students.end(); ++n) {
    if (isSame(name, *n)) {
      q.push(&(*n)); 
    } 
  }
  
  return q;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // STUDENT TODO: Implement this function.
  while (!matches.empty()) {
    std::string name = *matches.front();
    matches.pop();
    if (isSame(kYourName, name)) {
      return name;
    }
    
  }
  
  
  return "NO MATCHES FOUND.";
  
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
