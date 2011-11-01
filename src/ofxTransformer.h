#pragma once

#include <ofMain.h>

#include "ofxQuadWarper.h"

/**
    \class  Transformer
    \brief  a render transformer
**/
class ofxTransformer{

	public:
	
		ofxTransformer();
		
		/// set the desired render size compared to the given screen (or window) size,
		/// set handleAspectRatio to true if you want automatic letter/pillar boxing
		void setRenderSize(float w, float h, float screenWidth, float screenHeight);
		void setRenderSize(float w, float h);	/// use the full screen size
		float getRenderWidth()	{return _renderWidth;}
		float getRenderHeight()	{return _renderHeight;}
		
		/// enable/disable the transforms
		///
		/// set translate if you want to be able to move the origin
		/// set scale if you want to turn on automatic scaling to the screen size
		/// set warp if you want to enable to quad warper
		/// set handleAspect to true if you want automatic letter/pillar boxing
		///
		/// note: all of these options can also be enabled one by one
		///
		void setTransforms(bool translate, bool scale, bool warp=false, bool handleAspect=false);
		
		/// set the render scale directly
		void setRenderScale(float x, float y);
		float getRenderScaleX()	{return _renderScaleX;}
		float getRenderScaleY()	{return _renderScaleY;}
		
		/// turn on/off automatic screen scaling
		virtual void setScale(bool scale)	{_bScale = scale;}
		bool getScale() 					{return _bScale;}
		
		/// keep the aspect ratio when scaling?
		virtual void setAspect(bool aspect)	{_bHandleAspect = aspect;}
		bool getAspect()					{return _bHandleAspect;}
		
		/// screen mirroring
		virtual void setMirror(bool mirrorX, bool mirrorY);
		virtual void setMirrorX(bool mirrorX);
		virtual void setMirrorY(bool mirrorY);
		bool getMirrorX()		{return _bMirrorX;}
		bool getMirrorY()		{return _bMirrorY;}
		
		/// origin translation
		virtual void setOriginTranslate(bool translate)	{_bTranslate = translate;}
		bool getOriginTranslate()						{return _bTranslate;}
		
		/// set the origin position
		virtual void setOrigin(float x, float y, float z=0);
		virtual void setOrigin(ofVec2f point)	{setOrigin(point.x, point.y, 0);}
		virtual void setOrigin(ofVec3f point)	{setOrigin(point.x, point.y, point.z);}
		ofVec3f getOrigin()		{return _origin;}
		float getOriginX()		{return _origin.x;}
		float getOriginY()		{return _origin.y;}
		float getOriginZ()		{return _origin.z;}
		
		/// set/edit the quad projection warping
		virtual void setWarp(bool warp);
		bool getWarp()				{return _bWarp;}
		void resetWarp();
		bool loadWarpSettings(const string xmlFile="quadWarper.xml");
		void saveWarpSettings(const string xmlFile="quadWarper.xml");
		
		/// manually set/get the warp points
		/// index: 0 - upper left, 1 - upper right, 2 - lower right, 3 - lower left 
		void setWarpPoint(unsigned int index, ofVec2f point);
		ofVec2f getWarpPoint(unsigned int index);
		
		/// apply the transforms manually,
		/// these do not do a matrix push or pop
		void applyRenderScale();
		void applyMirrorX();
		void applyMirrorY();
		void applyOriginTranslate();
		void applyWarp();
				
	protected:
		
		bool _bScale, _bMirrorX, _bMirrorY, _bTranslate, _bHandleAspect, _bWarp;
		float _screenWidth, _screenHeight;	///< parent render size (screen or window)
		float _renderWidth, _renderHeight;	///< render size
		float _renderScaleX, _renderScaleY;	///< render scale
		float _renderAspect, _screenAspect;
		ofVec3f _origin;
		
		/// quad warper
		ofxQuadWarper _quadWarper;
};