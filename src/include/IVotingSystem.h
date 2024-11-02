/**
 * @file IVotingSystem.h
 * @author Michael Vang (vang2891@umn.edu)
 * @brief 
 * @version 0.1
 * @date 2023-03-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef IVOTINGSYSTEM_H
#define IVOTINGSYSTEM_H


#include "ISpecialCase.h"
#include "AuditFile.h"
#include "Display.h"

/**
 * @brief The abstract class for each voting election system will inherit from.
 * 
 */
class IVotingSystem {
	public:

		/**
		 * @brief To start the election process and handle special cases.
		 * 
		 * @return true if sucessful.
		 * @return false 
		 */
		virtual bool startElection() = 0;

		/**
		 * @brief A helper function to startElection.
		 * Is used to determine a winner.
		 * 
		 * @return true if winner was found.
		 * @return false 
		 */
		virtual bool conductElection() = 0;

		/**
		 * @brief Get the Audit File object
		 * 
		 * @return AuditFile* 
		 */
		AuditFile *getAuditFile() const { return audit; }

		/**
		 * @brief Set the Audit File object
		 * 
		 * @param auditFile_ AuditFile
		 */
		void setAuditFile(AuditFile *auditFile_) { 
			audit = auditFile_; 
			auditing = 1;	
			}

		/**
		 * @brief Get the Display Screen object
		 * 
		 * @return Display* 
		 */
		Display *getDisplayScreen() const { return displayScreen; }

		/**
		 * @brief Set the Display Screen object
		 * 
		 * @param displayScreen_ Display
		 */
		void setDisplayScreen(Display *displayScreen_) { displayScreen = displayScreen_; }

		/**
		 * @brief get the status of the election.
		 * 
		 * @return int 
		 */
		int getStatus() const { return status; }

		/**
		 * @brief Set the status of the election.
		 * 1 if complete.
		 * -1 if incomplete.
		 * 
		 * @param status_ int
		 */
		void setStatus(int status_) { status = status_; }

		/**
		 * @brief Get the write to audit option int.
		 * 
		 * @return int 
		 */
		int getAuditing() const { return auditing; }

		/**
		 * @brief Set the write to audit option int.
		 * 
		 * @param auditing_ int
		 */
		void setAuditing() { 
			if(auditing) {
				auditing = 0;
			};

			auditing = 1;
			}

		/**
		 * @brief Get the Special Cases vector
		 * 
		 * @return vector<ISpecialCase*> 
		 */
		vector<ISpecialCase*> getSpecialCase() const { return specialCase; }

		/**
		 * @brief Set the Special Cases vector
		 * 
		 * @param specialCase_ 
		 */
		void setSpecialCase(const vector<ISpecialCase*> &specialCase_) { specialCase = specialCase_; }

    protected:
    	vector<ISpecialCase*> specialCase; ///< Hold the methods of special cases handler
    	AuditFile *audit; ///< the audit file that will be produced
    	Display *displayScreen; ///< the display object

    	int status = -1; ///< 1 if election is complete and winner is found.
		int auditing = 0; ///< 1(true) if should write to audit. 0(False) to avoid audit.
};

#endif // IVOTINGSYSTEM_H

