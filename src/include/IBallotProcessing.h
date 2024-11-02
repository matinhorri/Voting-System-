/**
 * @file IBallotProcessing.h
 * @author Matin Horri (horri031@umn.edu)
 * @brief 
 * @version 0.1
 * @date 2023-03-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef IBALLOTPROCESSING_H_
#define IBALLOTPROCESSING_H_

#include <vector>
#include <cstdio>
#include "IVoteBallot.h"
#include "AuditFile.h"

class IBallotProcessing {
	public:
		/**
		* @brief Sets up the ballot processing object.
		* @return true if setup is successful, false otherwise.
		*/
		virtual bool setUp() = 0;
		/**
  		* @brief Reads ballots from the file.
  		* @return true if read is successful, false otherwise.
  		*/
		virtual bool read() = 0;
		/**
  		* @brief Returns the output of the ballot processing.
 		* @return A pointer to an IVoteBallot object representing the ballot.
  		*/
		virtual IVoteBallot* output() = 0;
		/**
  		* @brief Returns the file used for reading ballots.
  		* @return A pointer to a FILE object.
  		*/
		virtual FILE *getFile() const { return file; }
		/**
  		* @brief Sets the file used for reading ballots.
  		* @param file_ A pointer to a FILE object.
  		*/
		virtual void setFile(FILE *file_) { file = file_; }
		/**
  		* @brief Returns the number of ballot lines to read from the file.
  		* @return The number of ballot lines to read.
  		*/
		virtual int getBLinesToRead() const { return bLinesToRead; }
		/**
  		* @brief Sets the number of ballot lines to read from the file.
  		* @param bLinesToRead_ The number of ballot lines to read.
  		*/
		virtual void setBLinesToRead(int bLinesToRead_) { bLinesToRead = bLinesToRead_; }
		/**
  		* @brief Returns a pointer to the IVoteBallot object representing the ballot.
 		* @return A pointer to an IVoteBallot object.
  		*/
		virtual IVoteBallot *getVoteBallot() { return voteBallot; }
		/**
  		* @brief Sets the IVoteBallot object representing the ballot.
  		* @param voteBallot_ A pointer to an IVoteBallot object.
 		*/
		virtual void setVoteBallot(IVoteBallot *voteBallot_) { voteBallot = voteBallot_; }
		/**
  		* @brief Returns the map ballot.
  		* @return A vector of integers representing the map ballot.
  		*/
		virtual std::vector<int> getMapBallot() { return mapBallot; }
		/**
  		* @brief Sets the map ballot.
  		* @param mapBallot_ A vector of integers representing the map ballot.
  		*/
		virtual void setMapBallot(const std::vector<int> &mapBallot_) { mapBallot = mapBallot_; }
		/**
  		* @brief Returns the audit file.
  		* @return A pointer to an AuditFile object.
 		*/
		AuditFile* getAudit() const { return audit; }
		/**
  		* @brief Sets the audit file.
  		* @param audit_ A pointer to an AuditFile object.
  		*/
		void setAudit(AuditFile* audit_) { 
			audit = audit_; 
			auditing = 1;
		}
		/**
  		* @brief Returns the audit status.
  		* @return 1 if auditing is enabled, 0 otherwise.
  		*/
		int getAuditing() const { return auditing; }

		/**
  		* @brief Sets the auditing.
  		* @param auditing_ to the auditing.
  		*/
		void setAuditing(int auditing_) { auditing = auditing_; }

		/**
		 * @brief Get the total amount of ballots.
		 * 
		 * @return int 
		 */
		int getTotalBallots() const { return totalBallots; }

		/**
		 * @brief Set the total amount of ballots.
		 * 
		 * @param totalBallots_ 
		 */
		void setTotalBallots(int totalBallots_) { totalBallots = totalBallots_; }

		/**
		 * @brief Get the list of invalid files.
		 * 
		 * @return std::vector<string> 
		 */
		std::vector<string> invalidFiles() const { return invalid_files; }

		/**
		 * @brief Set the list of invalid files.
		 * 
		 * @param invalidFiles 
		 */
		void setInvalidFiles(const std::vector<string> &invalidFiles) { invalid_files = invalidFiles; }

    protected:
    	FILE *file;
		std::vector<string> files = {"N/A"};
		std::vector<string> invalid_files;

    	int bLinesToRead;
		int totalBallots = 0;
    	IVoteBallot *voteBallot;
    	std::vector<int> mapBallot;

		AuditFile* audit;
		int auditing = 0;
};


#endif // IBALLOTPROCESSING_H
