/***********************************************************************************************************************
 *Author: HieuPM
 *Date Modifed: 23/06/2017 9h20
 *Name: HieuPM_CBasic_ass4
 **********************************************************************************************************************/
This program help you make a list of student with these function:
- Add a new student
- Find a student on the list
- Remove a student from the list
- Print the list


/Function1*************************************************************************************************************/
/*!
 *Function : {void} addStudent()
 * @brief: Add student querry
 *
 * @param: <none>
 *
 * @return: <none>.
 */
/Function2*************************************************************************************************************/
void addStudent();
/*!
 *Function : {void} addTopStudent()
 * @brief: Add a new student to the top of the list
 *
 * @param: pAdd - Poiter use for adding new student
 *
 * @return: <none>.
 */
/Function3*************************************************************************************************************/
void addTopStudent();
/*!
 *Function : {void} addBotStudent()
 * @brief: Add a new student to the bottom of the list
 *
 * @param: pAdd - Poiter use for adding  new student
 *
 * @return: <none>.
 */
/Function4*************************************************************************************************************/
void addBotStudent();
/*!
 *Function : {void} findStudent()
 * @brief: Find a student on the list
 *
 * @param: pFind - Poiter use for finding new student
 *
 * @return: <none>.
 */
/Function5*************************************************************************************************************/
void findStudent();
/*!
 *Function : {void} removeStudent()
 * @brief: Remove a student from the list
 *
 * @param:  pBefore - Temporary Pointer use to point the address before the address we want to remove
            pRemove - Temporary Pointer use to point the address we want to remove
            pAddress - The address have the same name with the user input
            pTemp - Temporary Pointer use to point the address before pTail
 *
 * @return: <none>.
 */
/Function6*************************************************************************************************************/
void removeStudent();
/*!
 *Function : {student_t *} findStudentTool()
 * @brief: find the address which had the student name matched user input
 *
 * @param: pFind - Poiter use for finding a student on the list
 *
 * @return: pFind - = NULL if there is no match
                    != NULL if there is a match
 */