/**
 * UndoRedoInterface.h
 *
 *  Created on: 13.06.2009
 *      Author: Alexey Kukushkin
 */

#ifndef UNDOREDOINTERFACE_H_
#define UNDOREDOINTERFACE_H_

class UndoRedoInterface
{
	public:

		/**
		*	�����������.
		*/
		UndoRedoInterface(){}

		/**
		*	����������.
		*/
		virtual ~UndoRedoInterface(){}
};

/**
 * ���������� ����������
 */
Q_DECLARE_INTERFACE( UndoRedoInterface, "com.alxn1.MultiFusion.TimelineInterface/1.0" )


/**
*	�������� ��������� �� ����� ������ � ���������� �� ��������� TimelineInterface.
*
*	@return ���������� ��������� ��� 0, ���� ��������� ������.
*/
template < class T > inline UndoRedoInterface* UNDOREDO( T *o )
{
	return qobject_cast< UndoRedoInterface* >( o );
}
#endif /* UNDOREDOINTERFACE_H_ */
