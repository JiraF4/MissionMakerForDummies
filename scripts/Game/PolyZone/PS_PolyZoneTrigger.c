
class PS_PolyZoneTriggerClass: SCR_BaseTriggerEntityClass
{
	
}

class PS_PolyZoneTrigger : SCR_BaseTriggerEntity
{
	PS_PolyZone m_polyZone;
	
	[Attribute()]
	ref PS_PolyZoneEffect m_polyZoneEffect;
	
	override void OnInit(IEntity owner)
	{
		m_polyZone = PS_PolyZone.Cast(owner.GetParent().FindComponent(PS_PolyZone));
	}
	
	override bool ScriptedEntityFilterForQuery(IEntity ent)
	{
		if (!IsAlive(ent))
			return false;
		
		if (!m_polyZone.IsInsidePolygon(ent.GetOrigin()))
			return false;
		
		return true;	
	}
	
	override protected void OnActivate(IEntity ent)
	{
		PS_PolyZoneEffectHandler polyZoneEffectHandler = PS_PolyZoneEffectHandler.Cast(ent.FindComponent(PS_PolyZoneEffectHandler));
		polyZoneEffectHandler.AddEffect(this, m_polyZoneEffect);
	}
	
	override protected void OnDeactivate(IEntity ent)
	{
		PS_PolyZoneEffectHandler polyZoneEffectHandler = PS_PolyZoneEffectHandler.Cast(ent.FindComponent(PS_PolyZoneEffectHandler));
		polyZoneEffectHandler.RemoveEffect(this, m_polyZoneEffect);
	}
	
	/*
	override protected void OnQueryFinished(bool bIsEmpty){ 
		super.OnQueryFinished(bIsEmpty);
		if (bIsEmpty)
			return;
		
		array<IEntity> outEntities = new array<IEntity>();
		int entitiesCount = GetEntitiesInside(outEntities);
		
	};
	*/
}