/*
 * TutorialsInterface.h
 *
 *  Created on: 18.04.2009
 *      Author: Trinity
 */

#ifndef TUTORIALSINTERFACE_H_
#define TUTORIALSINTERFACE_H_

class TutorialsInterface: public QWidget
{
	public:
		/**
		 * �����, ������������ ��������� ������� � ��������� ����������.
		 */
		virtual void show(QString id, QString caption) = 0;

		/**
		*	�����������.
		*/
		TutorialsInterface(){}

		/**
		*	����������.
		*/
		virtual ~TutorialsInterface(){}
};

/**
 * ���������� ����������
 */
Q_DECLARE_INTERFACE( TutorialsInterface, "ifmo.lothe.TutorialsInterface/1.0" )


/**
*	�������� ��������� �� ����� ������ � ���������� �� ��������� SaveSVGInterface.
*
*	@return ���������� ��������� ��� 0, ���� ��������� ������.
*/
template < class T > inline TutorialsInterface* TUTORIALS( T *o )
{
	return qobject_cast< TutorialsInterface* >( o );
}

#endif /* TUTORIALSINTERFACE_H_ */
